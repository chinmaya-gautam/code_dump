#!/usr/bin/perl
#loopuntil.plx

use warnings;
use strict;

my $input;
my $stop;

until($stop){
print "i will not stop until you give me the password.\n";
$input = <STDIN>;
chomp $input;
if($input eq "please stop"){
$stop=1;
}

}