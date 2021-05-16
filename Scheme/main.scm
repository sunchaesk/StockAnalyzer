
(use-modules (ice-9 regex)
             (ice-9 rdelim))

(define (split-semi str)
  (map match:substring (list-matches "[^;]+" str)))

(define (p-read-file str)
  (call-with-input-file str
    (lambda (input-port)
      (let loop ((x (read-char input-port)))
        (if (not (eof-object? x))
            (begin
              (display x)
              (loop (read-char input-port))))))))

(define (read-file filename)
  (call-with-input-file filename
    (lambda (p)
      (let loop ((line (read-line p))
                 (result '()))
        (if (eof-object? line)
            (reverse result)
            (loop (read-line p) (cons line result)))))))

;; (define (read-file s)
;;   (call-with-input-file s
;;     (lambda (input-port)
;;       (let loop ((x (read-char input-port))
;;                  (ret (string "")))
;;         (if (not (eof-object? x))
;;             (begin
;;               (display x)
;;               (loop (read-char input-port)
;;                     (string-append ret x))))))))
