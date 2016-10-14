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

WD     = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
TPLDIR = ../templates
SRC    = $(wildcard *.md)

.PHONY: all
all: $(SRC:.md=.html) $(SRC:.md=.pdf)

.PHONY: clean
clean:
	$(RM) $(SRC:.md=.html) $(SRC:.md=.pdf)

%.html: %.md
	$(PAN) $(PANFLAGS) $(PANFLAGS_SLIDES) -o $@ $<

%.pdf: %.html
	$(TOPDF) $(TOPDFFLAGS) "file://$(WD)$<?print-pdf" $@
