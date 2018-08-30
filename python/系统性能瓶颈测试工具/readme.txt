1.安装图形化插件   最新版本   
 yum list available 'graphviz*'
        yum install 'graphviz*'
		
2.下载gprof2dot.py文件
		http://pan.baidu.com/s/1c0es6q8  (我的网盘地址)
		https://code.google.com/p/jrfonseca/wiki/Gprof2Dot
		
3.1首先执行 gcc -pg -o tmp tmp.c，然后运行该程序./tmp，程序运行完成后会在当前目录下生成gmon.out文件（这个文件gprof在分析程序时需要），
3.2再执行gprof ./tmp | gprof2dot.py |dot -Tpng -o report.png，打开report.png结果：
            gprof ./tmp | ./gprof2dot.py -n0 -e0 | dot -Tpng -o output.png


		