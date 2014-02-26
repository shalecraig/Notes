I initially created this template directory for school notes, but have started
using it to take notes on books and music I experience.

Someday I may publish these sets of notes, but for now, this is what I'm
posting.

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

To add a new section, run the script `s/newCourse`.

To build, run the makefile. I like to use something along the lines of
`make -j 4` to build the notes in parallel.

If you have any questions, feel free to send in pull requests.

I plan on extending this to also compile `latex` for the web, but I don't have
the patience nor need to do this right at this moment. Running `htlatex` is
enough for the 1-offs I need right now.

# Wishlist:
- Compile using `htlatex` _and_ `pdflatex`. *3 minutes*

- Do _really good_ compile-time spell-checking. *no clue*

- Figure out how addons will work. *1 Hour*

- Build in some docco integration addon. *2 Hours*
