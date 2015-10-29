#!/usr/bin/perl
#directory.plx

use warnings;
use strict;

print "Contents of the present directory: ";
opendir DH,"." or die "could not open the current directory: $!\n";

while($_=readdir(DH)){
	next if $_ eq "." or $_ eq "..";
	print $_," "x (30-length($_));
	print "d" if -d $_;
	print "r" if -r _;
	print "w" if -w _;
	print "x" if -x _;
	print "o" if -o _;
	print "\t";
	print -s _ if -r _ and -f _;
	print "\n";
}