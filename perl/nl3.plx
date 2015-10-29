#!/usr/bin/perl
#nl3.plx

use warnings;
use strict;

my $linenumber=1;
my $current="";

while(<>){
	if($current ne $ARGV){
		$current=$ARGV;
		print "\n\n\t\tFILE: $ARGV\n\n";
		$linenumber=1;
	}
print $linenumber++," : $_";
}
print "\n";