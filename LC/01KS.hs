import Control.Monad
import Control.Monad.ST
import Data.Array.ST
import Data.Array.MArray

-- 0-1 Knapsack: Given weights, values, and cap, find the max value achievable
knapsack :: Int -> [(Int, Int)] -> Int
knapsack cap items = runST $ do
    -- Create a mutable array dp[0..cap], initialized to 0
    dp <- newArray (0, cap) 0 :: ST s (STArray s Int Int)

    -- Process each item (weight, value)
    forM_ items $ \(w, v) -> do
        -- Traverse the array from right to left to avoid overwriting data prematurely
        forM_ [cap, cap - 1 .. w] $ \j -> do
            -- Update dp[j] = max(dp[j], dp[j - w] + v)
            oldVal <- readArray dp j
            prevVal <- readArray dp (j - w)
            writeArray dp j (max oldVal (prevVal + v))

    -- The answer is in dp[cap]
    readArray dp cap

-- Example usage
main :: IO ()
main = do
    let cap = 10
        wts = [1..1000]
        vals = [1..500]
        items = [(wt, val) | wt <- wts, val <- vals]
    -- print items
    -- print $ length items
    print $ knapsack cap items

