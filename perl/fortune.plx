#!/usr/bin/perl
#fortune.plx
use warnings;
use strict;

$/="\n%\n";

open QUOTES,"quotes.dat" or die $!;
my @file = <QUOTES>;
my $fortune=$file[rand(@file)];
chomp $fortune;

print $fortune,"\n";