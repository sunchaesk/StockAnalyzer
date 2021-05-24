
(use-modules (ice-9 regex)
             (ice-9 rdelim))
(include "utils.scm")

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

;; 2021-03-12;234.00999;235.82001;233.23000;235.75000;22647900
(define data  (make-record-type "data "'(datetime
                                         open
                                         high
                                         low
                                         close
                                         volume)))
(define make-data (record-constructor data '(datetime
                                             open
                                             high
                                             low
                                             close
                                             volume)))
(define get-data-datetime (record-accessor data 'datetime))
(define get-data-open (record-accessor data 'open))
(define get-data-high (record-accessor data 'high))
(define get-data-low (record-accessor data 'low))
(define get-data-close (record-accessor data 'close))
(define get-data-volume (record-accessor data 'volume))

;; 2021-03-12;234.00999;235.82001;233.23000;235.75000;22647900
(define (to-data s)
  (let ((l (split-semi s)))
    (make-data (list-ref l 0)
               (list-ref l 1)
               (list-ref l 2)
               (list-ref l 3)
               (list-ref l 4)
               (list-ref l 5))))

(define (readlines filename)
  (call-with-input-file filename
    (lambda (p)
      (let loop ((line (read-line p))
                 (result '()))
        (if (eof-object? line)
            (reverse result)
            (loop (read-line p) (cons line result)))))))

(define (file-to-data filename)
  (map to-data (readlines filename)))


(define test-l '(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15))

(define (frame-init l s)
  (frame l s 1))

(define (frame l s start)
  (if (= start (- (length l) 2))
      (display (slice l start s))
      (begin
        (display (slice l start s))
        (frame l s (+ 1 start)))))


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
