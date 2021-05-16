
(defstruct data
  datetime
  open
  high
  low
  close
  volume)

(defun split-str (string &optional (separator " "))
  (split-1 string separator))

(defun to-data (data-str)
  (let (data-split-str (split ))))

(defun read-file (fname)
  (with-open-file (stream fname)
    (do ((line (read-line stream nil)
               (read-line stream nil)))
        ((null line))
      (print line))))
