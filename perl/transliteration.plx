#!/usr/bin/perl
#transliteration.plx

use warnings;
use strict;

my $story= <<EOF;

this is a short story about engineering students
defn: an engineering student is a student who studies (or pretends to study) engineering
engineering is a term derived from an engineer which was coined from ingenium which means
to inovate, thus all engineering students are supposed to innovative.

there is a huge difference between the child which goes into an engineering college as a freshman
and the engineer who comes out with a degree.Four years of life in an engineering college bring about
this transform...

EOF

print "\n\n the story goes as: $_";

my $vovels = $story =~ tr/aeiou//;
print "\n\n\n the number of vovels: $vovels\n";
print "\nthe story with vovels heighlighted:\n\n";

my $count =32;
foreach my $i (qw(a e i o u)){
$story =~ s/$i/\033[0${count}m$i\033[0m/ig;
$count++;
}
print $story;