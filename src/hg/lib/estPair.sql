# estPair.sql was originally generated by the autoSql program, which also 
# generated estPair.c and estPair.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#EST 5'- 3' pairing information
CREATE TABLE estPair (
    chrom varchar(255) not null,	# Chromosome name
    chromStart int unsigned not null,	# Start position in chromosome
    chromEnd int unsigned not null,	# End position in chromosome
    mrnaClone varchar(255) not null,	# Mrna clone name
    acc5 varchar(255) not null,	# 5' EST accession number
    start5 int unsigned not null,	# Start position of 5' EST in chromosome
    end5 int unsigned not null,	# End position of 5' EST in chromosome
    acc3 varchar(255) not null,	# 3' EST accession number
    start3 int unsigned not null,	# Start position of 3' EST in chromosome
    end3 int unsigned not null,	# End position of 3' EST in chromosome
              #Indices
    INDEX (chrom(12), chromStart)
);