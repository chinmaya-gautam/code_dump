#!/usr/bin/perl
#match2.plx

use warnings;
use strict;

my $_ = "Nobody wants to hurt you... 'cept, I do hurt people sometimes, Case.";

print "'I do' is in the string\n" if (/I do/);
print "'sometimes Case' is in the sting\n" if (/sometimes Case/);