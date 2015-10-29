#!/usr/bin/perl
#headline.plx

use warnings;
use strict;



open LYNX,"lynx -source http://news.google.com/ |" or die "can't open lynx: $!\n";
while(<LYNX>){
if(m{<span class="section-name">(.*?)</span>}i){
print "\n\n\033[046m\033[033m\t\t$1\t\t\033[0m\033[0m\n\n";
}
if(m{<span class="titletext">(.*?)</span>}i){
print "$1\n";
}
}
print "\n";