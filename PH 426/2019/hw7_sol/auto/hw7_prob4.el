(TeX-add-style-hook
 "hw7_prob4"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "usletter" "12pt")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art12"
    "amsmath"
    "enumitem"
    "graphicx"
    "pdfpages"))
 :latex)

