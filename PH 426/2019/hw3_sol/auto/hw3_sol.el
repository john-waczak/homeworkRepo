(TeX-add-style-hook
 "hw3_sol"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "usletter" "12pt")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art12"
    "amsmath"
    "enumitem"
    "graphicx"))
 :latex)

