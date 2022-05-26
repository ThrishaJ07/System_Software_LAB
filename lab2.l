%{
	#include "y.tab.h"
%}
%%
a {return A;}
b {return B;}
"\n" {return ENTER;}
. {printf("\nInvalid Input");exit(0);}
%%

