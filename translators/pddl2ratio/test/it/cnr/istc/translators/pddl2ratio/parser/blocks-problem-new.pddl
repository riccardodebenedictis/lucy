(define (problem BLOCKS-4-0)

(:domain BLOCKS-object-fluents)

(:objects A B C D - block)

(:INIT 	(= (on-block A) no-block) 
	(= (on-block B) no-block) 
	(= (on-block C) no-block) 
	(= (on-block D) no-block)
	(on-table A) 
	(on-table B)
	(on-table C) 
	(on-table D)
	(= (in-hand) no-block))

(:goal (AND (= (on-block C) D) (= (on-block B) C) (= (on-block A) B))))

