#!/usr/bin/perl
#logfile.plx

use warnings;
use strict;

my $logging = "file";	#change this to "file" to write to logfile!

if ($logging eq "file"){
	open LOG,">output.log" or die $!;
	select LOG;
}

print "program started: ", scalar localtime, "\n";
sleep 30;
print "program finished: ",scalar localtime, "\n";

select STDOUT;