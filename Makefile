# This is the makefile I use to organize/build/etc my school notes.
#
# The general directory structure is as follows:
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
# Phone & Full notes are formatted either as 8.5x11 or iPhone sized.


# Find the notes/assignment/lab files:
_typeset_full_notes_tex = $(wildcard ./**/notes/typeset_full*.tex)
_typeset_phone_notes_tex = $(wildcard ./**/notes/typeset_phone*.tex)
_typeset_note_tex = $(_typeset_full_notes_tex) $(_typeset_phone_notes_tex)
_typeset_note_pdfs = $(_typeset_note_tex:%.tex=%.pdf)

_typeset_notes_for_other_formats_unfiltered = $(wildcard ./**/notes/notes.tex)
_typeset_notes_for_other_formats_filtered = $(filter-out ./se380/notes/notes.tex, $(_typeset_notes_for_other_formats_unfiltered))

_typeset_note_mds = $(_typeset_notes_for_other_formats_filtered:%.tex=%.md)
_typeset_note_html = $(_typeset_notes_for_other_formats_filtered:%.tex=%.html)

_wkrpt_tex = $(wildcard ./**/uw-wkrpt-*.tex )
_wkrpt_pdfs = $(_wkrpt_tex:%.tex=%.pdf)
_assignment_tex = $(wildcard ./**/assignments/a*/a*.tex)
_assignment_pdfs = $(_assignment_tex:%.tex=%.pdf)
_lab_tex = $(wildcard ./**/labs/l*/*.tex)
_lab_pdfs = $(_lab_tex:%.tex=%.pdf)
_all_generated = $(_typeset_note_pdfs) $(_assignment_pdfs) $(_lab_pdfs) $(_wkrpt_pdfs) $(_typeset_note_mds) $(_typeset_note_html)

# Targets.
PHONY = list clean default all notes assignments labs wkrpts

default:
	@make all

list_notes:
	@echo $(_typeset_note_pdfs)

notes: $(_typeset_note_pdfs)
	@echo $^

labs: $(_lab_pdfs)
	@echo $^

assignments: $(_assignment_pdfs)
	@echo $^

list:
	echo $(PHONY)

all: $(_all_generated)
	@echo $^

wkrpts: $(_wkrpt_pdfs)
	@echo $^

clean:
	@rm -rf $(_all_generated)

# All notes that don't have sub-.text files in that dir.
.SECONDEXPANSION:
%.html: %.tex $$(dir $$<)notes.tex Makefile
	@echo "Making $@ using $^"
	@# Generate a notes
	@( pushd `dirname $<` && pandoc -s notes.tex --webtex --html5 -S -o notes.html && popd );

# All notes that don't have sub-.text files in that dir.
.SECONDEXPANSION:
%.md: %.html
	@echo "Making $@ using $^"
	@# This interprets the html file since the markdown doesn't generate images from math in tex files.
	@( pushd `dirname $<` && pandoc -s notes.html -S -o notes.md && popd );

# Will run pdflatex on all tex files that match a pdf target and are in the same
# directory as a notes.tex
# All notes that have sub-.tex files in that directory
.SECONDEXPANSION:
%.pdf: %.tex $$(dir $$<)notes.tex $$(dir $$<)/**/*.tex Makefile
	@echo "Making $@ using $^"
	@# TODO: make this just need to call pdflatex. There's a flag for this directory stuff.
	@if [ "$(*F)" == "typeset_full" ]; then \
		( pushd `dirname $<` && pdflatex -interaction=batchmode -jobname $(*F) notes.tex > /dev/null && pdflatex -interaction=batchmode -jobname $(*F) notes.tex > /dev/null && pdflatex -interaction=batchmode -jobname $(*F) notes.tex > /dev/null && popd ); \
	else \
		( pushd `dirname $<` && pdflatex -interaction=batchmode -jobname $(*F) "\def\isphone{1} \input{notes.tex}" > /dev/null && pdflatex -interaction=batchmode -jobname $(*F) "\def\isphone{1} \input{notes.tex}" > /dev/null && pdflatex -interaction=batchmode -jobname $(*F) "\def\isphone{1} \input{notes.tex}" > /dev/null && popd ); \
	fi
	@rm -f $*.{aux,log,out}

# All notes that don't have sub-.text files in that dir.
.SECONDEXPANSION:
%.pdf: %.tex $$(dir $$<)notes.tex Makefile
	@echo "Making $@ using $^"
	@# TODO: make this just need to call pdflatex. There's a flag for this directory stuff.
	@if [ "$(*F)" == "typeset_full" ]; then \
		( pushd `dirname $<` && pdflatex -interaction=batchmode -jobname $(*F) notes.tex > /dev/null && pdflatex -interaction=batchmode -jobname $(*F) notes.tex > /dev/null && pdflatex -interaction=batchmode -jobname $(*F) notes.tex > /dev/null && popd ); \
	else \
		( pushd `dirname $<` && pdflatex -interaction=batchmode -jobname $(*F) "\def\isphone{1} \input{notes.tex}" > /dev/null && pdflatex -interaction=batchmode -jobname $(*F) "\def\isphone{1} \input{notes.tex}" > /dev/null && pdflatex -interaction=batchmode -jobname $(*F) "\def\isphone{1} \input{notes.tex}" > /dev/null && popd ); \
	fi
	@rm -f $*.{aux,log,out}

# Matches essentially anything that isn't a note (assignments, quizzes, etc)
%.pdf: %.tex
	@( pushd `dirname $<` && pdflatex -interaction=batchmode `basename $<` > /dev/null && pdflatex -interaction=batchmode `basename $<` > /dev/null && pdflatex -interaction=batchmode `basename $<` > /dev/null && popd );
	rm -f $*.{aux,log,out}
