#!/usr/bin/perl
#joke.plx

use warnings;
use strict;

my @question = qw(Java Python Perl C);
my @punchlines = (
	"none, just change it once and its the same everywhere",
	"one, he just stands below the socket and the world revolves around him",
	"A million, one to change it and the rest to try and do it in fewer lines",
	'"CHANGE!!?"'
	);

for (0 .. $#question){
print "how many $question[$_] programmers does it need to change a lightbulb?\n";
sleep 5;
print "$punchlines[$_]\n\n";
sleep 2;
}
