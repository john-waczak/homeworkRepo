(TeX-add-style-hook
 "hw5_prob1"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "a4paper" "11pt")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art11"
    "enumitem"
    "geometry"
    "amsmath"
    "graphicx")
   (LaTeX-add-environments
    "solution"))
 :latex)

