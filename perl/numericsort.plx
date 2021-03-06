#!/usr/bin/perl
#numericsort.plx

use warnings;
use strict;

my $input=shift;
my $numeric=0;

if($input eq "-n"){
$input=shift;
$numeric=1;
}

my $output=shift;

open INPUT,$input or die "could not open $input: $!\n";
open OUTPUT,">$output" or die "could not open $output: $!\n";

my @file = <INPUT>;

if($numeric){
@file = sort {$a<=>$b} @file;
}else{
@file = sort @file;
}

print OUTPUT @file;
