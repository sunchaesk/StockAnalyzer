(use-modules (ice-9 regex)
             (ice-9 rdelim))

(define (list-ref lst n)
  (if (<= n 0)
      (car lst)
      (list-ref (cdr lst) (- n 1))))

(define (sub1 x)
  (- x 1))

(define (add1 x)
  (+ x 1))

;; the depr version is not working
(define depr-get-n-items
  (lambda (lst num)
    (if (>= num 0)
        (cons (car lst) (depr-get-n-items (cdr lst) (- num 1)))
        '()))) ;'
(define (get-n-items lst num)
  (if (null? lst)
      '()
      (cons (car lst)
            (get-n-items (cdr lst) (- num 1)))))

(define slice
  (lambda (lst start count)
    (if (> start 1)
        (slice (cdr lst) (- start 1) count)
        (get-n-items lst count))))

;; (define (__subseq lst start end i)
;;   (wh))
(define (subseq lst start end)
  (__subseq lst start end start))
