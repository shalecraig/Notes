This is the makefile I use to organize/build my school notes and notes I take
on books I read. Someday, I might publish both of those sets of notes, but for
now, this is what I'm posting.

For my school notes, I structure my notes as follows:
```
$tree template latex_templates
 template
 |-- assignments
 |   l-- a1
 |       |-- a1.pdf
 |       l-- a1.tex
 |-- labs
 |   l-- lab1
 |       |-- lab.pdf
 |       |-- lab.tex
 |       |-- prelab.pdf
 |       l-- prelab.tex
 l-- notes
     |-- notes.tex
     |-- typeset_full.pdf
     |-- typeset_full.tex -> ../../latex_templates/typeset_full.tex
     |-- typeset_phone.pdf
     l-- typeset_phone.tex -> ../../latex_templates/typeset_phone.tex
 latex_templates
 |-- typeset_full.tex
 l-- typeset_phone.tex
```

Phone & Full notes are formatted for iPhone 3G or 8.5x11 respectively.

To add a new section, run the script `s/new`.
