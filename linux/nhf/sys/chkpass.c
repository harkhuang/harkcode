#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <shadow.h>

int
main(int argc, char **argv)
{
	struct spwd *shadow_rec;
	char *input_key;
	char *epass;

	if (argc<2) {
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	shadow_rec = getspnam(argv[1]);
	if (shadow_rec==NULL) {
		printf("User does not exist.\n");
		exit(1);
	}

	input_key = getpass("Password: ");

	epass = crypt(input_key, shadow_rec->sp_pwdp);

	if (strcmp(epass, shadow_rec->sp_pwdp)==0) {
		puts("YES");
		return 0;
	} else {
		puts("NO");
		return 1;
	}
}

