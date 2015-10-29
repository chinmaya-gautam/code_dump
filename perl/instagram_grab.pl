#!/usr/bin/perl

use warnings;
use strict;

use LWP;

my $ua = LWP::UserAgent->new();

$ua->ssl_opts( verify_hostname => 0);

my $response = $ua->get("https://www.instagram.com/kfc") or die "could not get a response";

my $page =  $response->decoded_content;

my @page_strings = $page =~ m/\"code\"\:\"(.*?)\"/g;
#print @page_strings;

#make new urls
my @image_page_urls = ();

foreach my $str  (@page_strings){
    my $new_url = "https://www.instagram.com/p/$str";
 #   print "$new_url\n";
    @image_page_urls = (@image_page_urls, $new_url);
}

#iterate through each page and get the image url
my $counter =0;
foreach my $url (@image_page_urls){
    $counter++;
    my $new_page_response = $ua->get("$url") or die "could not get page $url";
    my $img_page = $new_page_response->decoded_content;
    if ($img_page =~ m/og\:image\" content\=\"(.*?)\"/){
	print "image: $1\n";
	my $img_response = $ua->get("$1") or die "could not get the image";
	my $image=$img_response->decoded_content;
	#save to file
	my $filename = "${counter}.jpg";
	print "\tsaving to file $filename\n";
	open FH, ">$filename";
	print FH $image;
	close FH;
    }
}




