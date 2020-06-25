reverseSentence::String->String
--reverseSentence str = unwords (reverse (words str))--
--reverseSentence str = unwords $ reverse $ words str--
reverseSentence = unwords $ reverse $ words