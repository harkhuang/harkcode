#build release rpm package
install(PROGRAMS ${output_dir}/RedTun DESTINATION bin)
install(FILES ${output_dir}/rd_config.yaml DESTINATION bin)

# 以下为RPM信息的设置，包名,概述，供应者，版本, 分组等等信息，通过其变量名称可以知道意思
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Redis client middleware")
set(CPACK_PACKAGE_VENDOR "Shein")
set(CPACK_PACKAGE_VERSION ${project_version})
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_RPM_PACKAGE_GROUP "Shein")
set(CPACK_RPM_PACKAGE_URL "https://www.shein.com")
set(CPACK_RPM_PACKAGE_DESCRIPTION "Redis client middleware")
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_SYSTEM_NAME "x86_64")
set(CPACK_RPM_PACKAGE_ARCHITECTURE "x86_64")
set(CPACK_RPM_PACKAGE_LICENSE "MIT Licence")
set(CPACK_PACKAGING_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# 设置默认生成器，RPM生成器会构建RPM安装包，其它还有TGZ/ZIP等
set(CPACK_GENERATOR "${package_type}")

# 安装前和安装后执行的shell脚本, 会打包到RPM中，安装时执行。这里可扩展性很强, 放在源码目录下即可
# set(CPACK_RPM_PRE_INSTALL_SCRIPT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/pre_script.sh)
# set(CPACK_RPM_POST_INSTALL_SCRIPT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/post_script.sh)

#引入CPack模块，必须的
include(CPack)