# This is the makefile I use to organize/build my school notes and notes I take
# on books I read. Someday, I might publish both of those sets of notes, but for
# now, this is what I'm posting.
#
# For my school notes, I structure my notes as follows:
# $tree courseTemplate latex_templates
#  course123
#  |-- assignments
#  |   l-- a1
#  |       |-- a1.pdf
#  |       l-- a1.tex
#  |-- labs
#  |   l-- lab1
#  |       |-- lab.pdf
#  |       |-- lab.tex
#  |       |-- prelab.pdf
#  |       l-- prelab.tex
#  l-- notes
#      |-- notes.tex
#      |-- typeset_full.pdf
#      |-- typeset_full.tex -> ../../latex_templates/typeset_full.tex
#      |-- typeset_phone.pdf
#      l-- typeset_phone.tex -> ../../latex_templates/typeset_phone.tex
#  latex_templates
#  |-- typeset_full.tex
#  l-- typeset_phone.tex
#
# Phone & Full notes are formatted for iPhone 3G or 8.5x11 respectively

# Find the notes/assignment/lab files:
_all_generated = $(wildcard ./**/labs/l*/*.tex)

# Targets. I have ~4 of these (notes/labs/etc)
PHONY = default all clean

default:
	@make all

all: $(_all_generated)
	@echo $^

clean:
	@rm -rf $(_all_generated)

# Will run pdflatex on all tex files that match a pdf target and are in the same
# directory as a notes.tex.
#
# This is definitely not as elegant as it should be.
.SECONDEXPANSION:
%.pdf: %.tex $$(dir $$<)notes.tex Makefile
	@echo "Making $<"
	@# TODO: make this just need to call pdflatex. There's a flag for this directory stuff.
	@if [ "$(*F)" == "typeset_full" ]; then \
		( pushd `dirname $<` && pdflatex -interaction=batchmode -jobname $(*F) notes.tex > /dev/null && pdflatex -interaction=batchmode -jobname $(*F) notes.tex > /dev/null && pdflatex -interaction=batchmode -jobname $(*F) notes.tex > /dev/null && popd ); \
	else \
		( pushd `dirname $<` && pdflatex -interaction=batchmode -jobname $(*F) "\def\isphone{1} \input{notes.tex}" > /dev/null && pdflatex -interaction=batchmode -jobname $(*F) "\def\isphone{1} \input{notes.tex}" > /dev/null && pdflatex -interaction=batchmode -jobname $(*F) "\def\isphone{1} \input{notes.tex}" > /dev/null && popd ); \
	fi
	@rm -f $*.{aux,log,out}

%.pdf: %.tex
	( cd `dirname $<` && pdflatex `basename $<` && pdflatex `basename $<` && pdflatex `basename $<`);
	rm -f $*.{aux,log,out}
