#!/usr/bin/perl
#dec2bin (converts decimal number to binary number)

use warnings;
use strict;

print "\nenter a number less than 256 :";
my $input = <STDIN>;

my $output=$input&0b00000001;
 $output+=($input&0b00000010)/0b00000010*10;
 $output+=($input&0b00000100)/0b00000100*100;
 $output+=($input&0b00001000)/0b00001000*1000;
 $output+=($input&0b00010000)/0b00010000*10000;
 $output+=($input&0b00100000)/0b00100000*100000;
 $output+=($input&0b01000000)/0b01000000*1000000;
 $output+=($input&0b10000000)/0b10000000*10000000;
print "$input in binary: $output \n";
