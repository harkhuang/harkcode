project(frame_work)

cmake_minimum_required(VERSION 2.8)

set(PROJECT_DIR  ../../)

#aux_source_directory(../../../src PROJECT_DIR/src/pub)

include_directories(${PROJECT_DIR}/include/pub.h  )


set(PUBFUNC  ${PROJECT_DIR}/src/pub_func)

aux_source_directory(PUBFUNC  ${PROJECT_DIR}/src/pub_func )

set(TEST  ${PROJECT_DIR}/src/test/main.cpp)

add_executable(frame_work  ${TEST}   ${PUBFUNC})


include_directories(${CMAKE_SOURCE_DIR}/cuemissionscontroller)

include_directories(${CAMKE_SOURCE_DIR}/libtcmalloc/include/gperftools)

include_directories(${CAMKE_SOURCE_DIR}/sec_encrypto )

include_directories(${CAMKE_SOURCE_DIR}/webservice_soap )

include_directories(${CAMKE_SOURCE_DIR}./libzdb )

link_directories(${CMAKE_SOURCE_DIR}	
        ${CMAKE_SOURCE_DIR}/mxfparser/lib/
        ${CMAKE_SOURCE_DIR}/mvc2api/lib/  
        /usr/lib/mysql
        ${CMAKE_SOURCE_DIR}/xmlparser/lib/
        ${CMAKE_SOURCE_DIR}/libzdb/lib
        /usr/local/mysql/lib/
        ${CMAKE_SOURCE_DIR}/usr_lib64/
        ${CAMKE_SOURCE_DIR}/libtcmalloc/lib
        ${CAMKE_SOURCE_DIR}/sec_encrypt/lib
        /mnt/oristar_sms_server_v1.0_20140905/libtcmalloc/lib
        /usr/lib64
)



add_executable(oristar_sms_server  main.cpp )

target_link_libraries(oristar_sms_server ssl crypto xerces-c-3.1 asdcp XmlParse SecInterface shttpd zdb mysqlclient pthread dl stdc++ mvc2api)


#########   BS_NOMARL
add_custom_command(TARGET ALL_BUILD
	POST_BUILD
# copy programe
	COMMENT "copy oristar_sms_server to /usr/local/smsserver"
	COMMAND rm -rf /usr/local/smsserver
	COMMAND mkdir -p /usr/local/smsserver/bin
	COMMAND cp -r ${CMAKE_CACHEFILE_DIR}/oristar_sms_server  /usr/local/smsserver/bin
	COMMAND chmod +x /usr/local/smsserver/bin/oristar_sms_server
# create database
	COMMENT 	"create database"
	COMMAND		mysqladmin -uroot -p123456 drop hermes -f;
	COMMAND		mysqladmin -uroot -p123456 create hermes;
	COMMAND		mysql -uroot -p123456 hermes < ./smsconfig/hermes.sql
)


