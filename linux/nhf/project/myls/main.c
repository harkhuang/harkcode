
#include	"myls_config.h"

global_config = {
	.inode = 0,
	.perm = 0,
	.hlink = 0,
	.user = 0,
	.group = 0,
	.size = 0,
	.mtime = 0,
	.fname = 1
};

int
main()
{
	/* Parse .conf, flush global_config */
	/* Check environ, flush global_config */
	/* Check option, flush global_config */
	while (1) {
		getopt();
	}
}

