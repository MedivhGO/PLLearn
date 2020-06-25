import PreLude hiding ((/=),(==),not,and,or,(&&),(||))
(==)::Bool->Bool->Bool
(==) True True = True
(==)False False = True
(==) __ = False
not :: Bool->Bool
not True = False
not _ = True
not' = (==False)
