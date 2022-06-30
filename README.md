# FASTQC
# Language: C++
# Input: TXT
# Output: DIR
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: AfterQC 0.9.6


PluMA plugin to run AfterQC (Chen et al, 2017) quality control

The plugin accepts as input a TXT file containing the names of the FASTQ
files to check.

It will output GOOD and BAD sequences in separate FASTQ files, for each input FASTQ file.

Note: AfterQC is included with this plugin, and is also under the same MIT License, all rights reserved.
