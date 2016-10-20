((c-mode .
	 ((c-file-style . "gnu")
	  (eval . (flycheck-mode 1))
	  (flycheck-clang-include-path . ("/home/isryu/tmp/lnf-type-system/"
					  "/home/isryu/tmp/lnf-type-system/include"))
	  (eval . (semantic-mode 1))
	  (eval . (semantic-add-system-include . ("/home/isryu/tmp/lnf-type-system")))
	  (eval . (semantic-add-system-include . ("/home/isryu/tmp/lnf-type-system/include"))))))
