# nestedRepeats.sql was originally generated by the autoSql program, which also 
# generated nestedRepeats.c and nestedRepeats.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#BED12+ describing joined (by ID) fragments of repeats from RepeatMasker.
CREATE TABLE nestedRepeats (
    bin smallint not null,      # Bin number for browser speedup
    chrom varchar(255) not null,	# Chromosome (or contig, scaffold, etc.)
    chromStart int unsigned not null,	# Start position in chromosome
    chromEnd int unsigned not null,	# End position in chromosome
    name varchar(255) not null,	# Name of item
    score int unsigned not null,	# for BED compatibility -- No meaning for nestedRepeats
    strand char(1) not null,	# +, -, or . for mixed (some fragments +, some -)
    thickStart int unsigned not null,	# for BED compatibility -- same as chromStart
    thickEnd int unsigned not null,	# for BED compatibility -- same as chromEnd
    reserved int unsigned not null,	# for BED compatibility
    blockCount int not null,	# Number of blocks
    blockSizes longblob not null,	# Comma separated list of block (fragment) sizes
    chromStarts longblob not null,	# Start positions relative to chromStart
    blockStrands longblob not null,	# Strand of each fragment.
    id int unsigned not null,	# RepeatMasker-assigned ID used to join fragments.
    repClass varchar(255) not null,	# Class of repeat
    repFamily varchar(255) not null,	# Family of repeat
              #Indices
    INDEX(bin,chrom(20)),
    INDEX(chrom(20),chromStart)
);