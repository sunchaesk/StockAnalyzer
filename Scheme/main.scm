
(use-modules (ice-9 regex)
             (ice-9 rdelim))
(include "utils.scm")
(include "data_record.scm")

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

(define (__read-file filename)
  (call-with-input-file filename
    (lambda (p)
      (let loop ((line (read-line p))
                 (result '()))
        (if (eof-object? line)
            (reverse result)
            (loop (read-line p) (cons line result)))))))
(define (read-file filename)
  (reverse (__read-file filename)))

;; file -> string of lines (each line 1 elem)
(define (readlines filename)
  (call-with-input-file filename
    (lambda (p)
      (let loop ((line (read-line p))
                 (result '()))
        (if (eof-object? line)
            (reverse result)
            (loop (read-line p) (cons line result)))))))

;; file -> list of data
(define (file-to-data filename)
  (map to-data (readlines filename)))


(define test-l '(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15))

(define (frame-init l len)
  (frame l len 1))

(define (frame l len start)
  (if (= start (- (length l) 2))
      (display (slice l start len))
      (begin
        (display (slice l start len))
        (frame l len (+ 1 start)))))

;; list of string -> list of data
(define (frame-to-data l)
  (if (null? l)
      '()
      (cons (to-data (car l))
            (frame-to-data (cdr l)))))

;; almost basically the main loop
(define (frame-data l len start)
  (if (= start (length l))
      (frame-to-data (slice l start len))
      (begin
        (frame-to-data (slice l start len))
        (frame-data l len (+ 1 start)))))

(define test-l2
  (read-file "../data/msft.txt"))
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

;; (define (temp--read-file-line f lst)
;;   (let* ((l (read-line f)))
;;     (if (eof-object? l)
;;         lst
;;         (temp--read-file-line f (cons lst
;;                                 (make-data l))))))

;; (define )
