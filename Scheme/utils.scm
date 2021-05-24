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

(define get-n-items
  (lambda (lst num)
    (if (> num 0)
        (cons (car lst) (get-n-items (cdr lst) (- num 1)))
        '()))) ;'

(define slice
  (lambda (lst start count)
    (if (> start 1)
        (slice (cdr lst) (- start 1) count)
        (get-n-items lst count))))
