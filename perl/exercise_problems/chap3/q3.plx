#!/usr/bin/perl
#jokemachine

use warnings;
use strict;

my %jokes=(
    C => "change?",
    Perl => "a million, one to change and the rest to do it in fewer lines",
    Java => "you change it at one place and the result reflects everywhere",
    Python => "one, just stands below the socket and the whole world revolves around him"
);

for (keys %jokes){
print "how many $_ programmers does it take to change a lightbulb?\n";
sleep(5);
print "$jokes{$_}\n\n";
sleep(5);
}