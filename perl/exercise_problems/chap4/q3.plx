#!/usr/bin/perl
#prime numbers

use warnings;
use strict;

die "usage: <q3.plx> <ineger greater than 2>\n" unless $ARGV[0];

my $value=2;
while($value++ < $ARGV[0]){
    my $notprime =0;
for(2 .. $value/2){
    $notprime=1 unless($value % $_);
}
print "$value " unless $notprime;

}; 
print "\n";