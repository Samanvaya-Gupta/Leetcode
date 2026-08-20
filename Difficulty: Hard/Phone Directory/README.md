<h2><a href="https://www.geeksforgeeks.org/problems/phone-directory4628/1">Phone Directory</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a list of contacts <strong>contact[]</strong> and a query string<strong> s</strong>, implement a search for the phone directory. </span><span style="font-size: 18px;">For every prefix of <strong>s</strong>, starting from the first character and extending one character at a time, find all distinct contacts that start with that prefix. </span></p>
<p><span style="font-size: 18px;">The matching contacts for each prefix must be returned in lexicographical increasing order. </span><span style="font-size: 18px;">If no contact matches a prefix, return a list containing "0" for that prefix.</span></p>
<p><span style="font-size: 18px;">For example, if <strong>s</strong> = "geeips", the prefixes are ["g", "ge", "gee", "geei", "geeip", "geeips"]. The result should contain one list for each of these prefixes</span><span style="font-size: 18px;">.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input:</strong><span style="font-size: 18px;"> contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"}, s = "geeips"
</span><strong style="font-size: 18px;">Output:</strong><span style="font-size: 18px;">
[
    ["geeikistest", "geeksforgeeks", "geeksfortest"],
    ["geeikistest", "geeksforgeeks", "geeksfortest"],
    ["geeikistest", "geeksforgeeks", "geeksfortest"],
    ["geeikistest"],
    ["0"],
    ["0"]
]
</span><strong style="font-size: 18px;">Explanation: <br></strong><span style="font-size: 18px;">For the prefix "g", all three contacts match, so all three are returned in lexicographical increasing order.
For the prefixes "ge" and "gee", all three contacts still match.
For the prefix "geei", only "geeikistest" matches.
No contact starts with "geeip" or "geeips", so ["0"] is returned for both prefixes.</span></span></pre>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input:</strong><span style="font-size: 18px;"> contact[] = {"alice", "alex", "bob"}, s = "al"
</span><strong style="font-size: 18px;">Output:</strong><span style="font-size: 18px;">
[
    ["alex", "alice"],
    ["alex", "alice"]
]
</span><strong style="font-size: 18px;">Explanation: <br></strong><span style="font-size: 18px;">For the prefix "a", the matching contacts are "alex" and "alice".
For the prefix "al", both contacts still match. They are returned in lexicographical increasing order.</span></span></pre></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Snapdeal</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Map</code>&nbsp;<code>Trie</code>&nbsp;<code>Advanced Data Structure</code>&nbsp;