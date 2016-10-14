WD     = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
TPLDIR = ../templates

SRC  = $(wildcard *.md)
HTML = $(SRC:.md=.html)
PDF  = $(SRC:.md=.pdf)

PAN             = pandoc
PANFLAGS        = --smart
PANFLAGS_SLIDES = --to revealjs \
                  --no-highlight \
                  --slide-level 2 \
                  --template $(TPLDIR)/slides_template.html \
                  --variable TPLDIR:$(TPLDIR)

TOPDF      = wkhtmltopdf
TOPDFFLAGS = --orientation Landscape \
             --page-size A4

.PHONY: all
all: $(HTML) $(PDF)

.PHONY: clean
clean:
	$(RM) $(HTML) $(PDF)

%.html: %.md
	$(PAN) $(PANFLAGS) $(PANFLAGS_SLIDES) -o $@ $<

%.pdf: %.html
	$(TOPDF) $(TOPDFFLAGS) "file://$(WD)$<?print-pdf" $@
