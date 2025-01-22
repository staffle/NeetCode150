class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        # converts a freq_map into a hash value. Simple polynomial hashing.
        def get_hash(ans):
            PRIMES = [31, 23, 13]
            BIG_MODS= [1000000007, 1000000009, 998244353]
            def hash_func(freq_map, mod , prime):
                ans = 0
                multiplier = 1
                for i in freq_map:
                    ans = (ans + (i * multiplier) % mod) % mod
                    multiplier *= prime
                    multiplier %= mod
                return ans
            hashes = []
            for i in range(len(PRIMES)):
                hashes.append(hash_func(ans, BIG_MODS[i], PRIMES[i]))
            return hash_func(hashes, BIG_MODS[0], PRIMES[0])
    
        # creates an array of len 26 with freq of each char as value at every index 
        # where a is indexed as 0 , b is 1 and so on. returns it's hash value.
        def make_freq_map(s):
            ans = [0] * 26
            for ch in s:
                ans[ord(ch) - ord('a')] += 1
            return get_hash(ans)
        
        anagram_groups = []
        occured = dict()
        for s in strs:
            freq_map_hash = make_freq_map(s)
            if freq_map_hash not in occured:
                occured[freq_map_hash] = len(anagram_groups)
                anagram_groups.append([s])
            else:
                idx = occured[freq_map_hash]
                anagram_groups[idx].append(s)
        return anagram_groups
