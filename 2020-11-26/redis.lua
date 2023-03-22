local change = tonumber(ARGV[3])
if change == 1 then
	local exist = redis.call('SISMEMBER', KEYS[1], ARGV[1]) 
	if exist == 0 then
		redis.call("HINCRBY", KEYS[2], ARGV[2], change)
		redis.call("SADD", KEYS[1], ARGV[1])
	end	
else
	redis.call("HINCRBY", KEYS[2], ARGV[2], change)
	redis.call("SREM", KEYS[1], ARGV[1])
end


