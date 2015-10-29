#!/usr/bin/perl

use warnings;
use strict;

use LWP;

my $ua = LWP::UserAgent->new();

$ua->ssl_opts( verify_hostname => 0);

my $response = $ua->get("https://www.instagram.com/kfc") or die "could not get a response";

print $response->decoded_content;

;

