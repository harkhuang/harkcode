def do_log(log):
        with open('./log.txt', 'a') as file:
            print log
            log =   "="  + time.strftime('%y-%m-%d %H:%M:%S"',time.localtime(time.time())) + "===>" +log + "\n"
            #print log
            file.write(log)
            file.close()

