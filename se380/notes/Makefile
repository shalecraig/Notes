typeset:
	make typeset_full.pdf
	make typeset_phone.pdf

typeset_full.pdf: notes.tex
	pdflatex typeset_full.tex
	open typeset_full.pdf

typeset_phone.pdf: notes.tex
	pdflatex typeset_phone.tex
	open typeset_phone.pdf

force:
	make clean
	rm -rf typeset_{full,phone}.pdf typeset *.ignore
	make typeset

clean:
	rm -f build.tmp typeset_{full,phone}.{aux,log,out}

gg.ignore: notes.tex typeset
	git add typeset_{full,phone}.{pdf,tex}
	git commit -m "incremental commit of SE 380 notes"
	git push
	touch gg.ignore
