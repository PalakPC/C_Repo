#!/usr/bin/perl

#Perl script to print the instances of all ints and floats of code written in a file to another file along with line number.

use strict;
use warnings;
use Getopt::Long;

my($input, $output);
my $v = '';
my $f = '';

usage() if(@ARGV < 1 or !GetOptions('v' => \$v, 'f' => \$f, 'i=s' => \$input, 'o=s' => \$output));

sub usage {
	print "Unknown option: @_\n" if (@_);
	print "usage: program [--i inputfile] [--o outputfile]\n";
	exit;
}

my $regexv = qr|\b((int\|float)\s[A-Z, a-z, _]\w*(?!\())\b|;
my $regexf = qr|\b((int\|float)\s[A-Z, a-z, _]\w*)\b|;

open(FILE, "<$input");

open(OUT, ">$output");

if($v eq '1' && $f eq '') {
	while(<FILE>) {
		while(/$regexv/g) {
			print OUT "$1\t$.\n";
		}
	}
}

elsif($v eq '' && $f==1) {
	while(<FILE>) {
		while(/$regexf/g) {
			print OUT "$1\t$.\n";
		}
	}
}

else {
	print "Invalid arguments\n";
}
