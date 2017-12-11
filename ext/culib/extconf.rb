require 'mkmf-cu'

$srcs = Dir.glob("#{$srcdir}/*.{cu,c}").map {|n| File.basename(n) }

create_makefile('culib/culib')
