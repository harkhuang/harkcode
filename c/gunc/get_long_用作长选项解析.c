 /**********************************************************************
 # File Name:   get_long.c
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2014-12-13	
 ************************************************************************/
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
const char* program_name;
void print_usage (FILE* stream, int exit_code)
{
        fprintf (stream, "Usage: %s options [ inputfile ... ]\n", program_name);
        fprintf (stream, " -h --help                       显示这个帮助信息.\n"
                         " -o --output filename 将输出定位到文件.\n"
                         " -v --version                  打印版本信息.\n");
        exit (exit_code);
}

int main (int argc, char* argv[])
{
        int next_option;//下一个要处理的参数符号
        int haveargv = 0;//是否有我们要的正确参数，一个标识

        const char* const short_options = "ho:v";
        const struct option long_options[] = {
                { "help",        0,     NULL,    'h' },
                { "output",      1,     NULL,    'o' },
                { "version",     0,     NULL,    'v' },
                { NULL,          0,     NULL,     0  }};//最后一个元素标识为NULL

        const char *output_filename = NULL;
        int verbose = 0;
        program_name = argv[0];

        do
        {
                next_option = getopt_long (argc, argv, short_options, long_options, NULL);
                switch (next_option)
                {
                        case 'h':
                                haveargv = 1;
                                print_usage (stdout, 0);
                        case 'o':
                                output_filename = optarg;
                                haveargv = 1;
                                break;
                        case 'v':
                                verbose = 1;
                                haveargv = 1;
                                break;
                        case ':':
                                break;
                        case '?':
                                print_usage (stderr, 1);
                        case -1:
                                if (!haveargv)
                                {
                                        print_usage (stderr, 1);
                                 }
                                break;
                        default:
                                print_usage (stderr, 1);
                                break;
                }
        }while (next_option != -1);

        printf("optind.................%d\n",optind);

        if (haveargv)
        {
                int i;
                for (i = optind; i < argc; ++i)
                printf ("Argument: %s\n", argv[i]);
        }

        return 0;
}
