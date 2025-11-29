module Cv
	class Scalar
		def to_a
			[self[0], self[1], self[2], self[3]]
		end

		def to_s
			"<#{self.class.name}:[#{self.to_a.join(",")}]>"
		end
	end
end
