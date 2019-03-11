(TeX-add-style-hook
 "graph"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "12pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("caption" "labelfont=bf")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art12"
    "graphicx"
    "caption"))
 :latex)

