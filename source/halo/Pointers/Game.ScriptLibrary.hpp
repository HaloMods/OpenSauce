/*
	Yelo: Open Sauce SDK
	Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#if !PLATFORM_IS_DEDI
#include "Pointers/1.10/HaloCE_110_Runtime.Game.HS.inl"
#include "Pointers/1.10/HaloCE_110_Runtime_Manual.Game.HS.inl"
#else
#include "Pointers/1.10/HaloCE_110_Dedi.Game.HS.inl"
#include "Pointers/1.10/HaloCE_110_Dedi_Manual.Game.HS.inl"
#endif

#include <blam/hs/hs_structures.hpp>
#include <Memory/MemoryInterface.hpp>
#include <yelo/memory/memory_interface_base.hpp>

namespace Yelo
{
	namespace Scripting
	{
		FUNC_PTR(HS_MACRO_FUNCTION_PARSE, DUO_PTR(K_HS_MACRO_FUNCTION_PARSE));
		FUNC_PTR(HS_COMPILE_AND_EVALUATE, DUO_PTR(K_HS_COMPILE_AND_EVALUATE));
		FUNC_PTR(HS_NULL_EVALUATE, DUO_PTR(K_HS_NULL_EVALUATE));
		FUNC_PTR(HS_NULL_WITH_PARAMS_EVALUATE, DUO_PTR(K_HS_NULL_WITH_PARAMS_EVALUATE));

		//////////////////////////////////////////////////////////////////////////
		// script functions related
		ENGINE_PTR(int32, hs_function_table_count, DUO_PTR(K_HS_FUNCTION_TABLE_COUNT_PTR));
		ENGINE_DPTR(hs_function_definition, hs_function_table, DUO_PTR(K_HS_FUNCTION_TABLE));

		#pragma region hs function table references
		static int16* K_HS_FUNCTION_TABLE_COUNT_REFERENCES_16bit[] = {
			CAST_PTR(int16*, K_HS_FUNCTION_TABLE_COUNT_REFERENCE_16BIT_0),
			CAST_PTR(int16*, K_HS_FUNCTION_TABLE_COUNT_REFERENCE_16BIT_1),
		};
		static int32* K_HS_FUNCTION_TABLE_COUNT_REFERENCES_32bit[] = {
			CAST_PTR(int32*, K_HS_FUNCTION_TABLE_COUNT_REFERENCE_32BIT_0),
		};

		// really hs_function_definition***
		static void* K_HS_FUNCTION_TABLE_REFERENCES[] = {
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_0),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_1),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_2),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_3),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_4),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_5),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_6),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_7),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_8),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_9),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_10),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_11),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_12),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_13),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_14),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_15),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_16),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_17),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_18),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_19),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_20),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_21),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_22),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_23),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_24),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_25),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_26),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_27),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_28),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_29),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_30),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_31),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_32),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_33),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_34),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_35),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_36),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_37),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_38),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_39),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_40),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_41),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_42),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_43),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_44),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_45),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_46),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_47),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_48),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_49),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_50),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_51),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_52),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_53),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_54),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_55),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_56),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_57),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_58),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_59),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_60),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_61),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_62),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_63),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_64),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_65),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_66),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_67),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_68),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_69),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_70),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_71),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_72),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_73),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_74),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_75),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_76),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_77),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_78),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_79),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_80),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_81),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_82),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_83),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_84),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_85),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_86),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_87),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_88),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_89),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_90),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_91),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_92),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_93),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_94),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_95),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_96),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_97),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_98),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_99),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_100),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_101),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_102),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_103),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_104),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_105),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_106),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_107),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_108),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_109),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_110),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_111),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_112),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_113),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_114),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_115),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_116),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_117),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_118),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_119),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_120),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_121),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_122),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_123),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_124),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_125),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_126),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_127),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_128),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_129),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_130),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_131),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_132),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_133),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_134),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_135),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_136),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_137),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_138),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_139),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_140),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_141),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_142),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_143),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_144),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_145),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_146),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_147),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_148),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_149),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_150),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_151),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_152),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_153),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_154),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_155),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_156),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_157),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_158),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_159),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_160),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_161),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_162),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_163),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_164),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_165),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_166),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_167),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_168),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_169),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_170),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_171),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_172),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_173),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_174),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_175),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_176),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_177),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_178),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_179),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_180),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_181),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_182),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_183),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_184),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_185),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_186),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_187),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_188),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_189),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_190),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_191),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_192),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_193),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_194),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_195),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_196),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_197),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_198),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_199),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_200),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_201),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_202),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_203),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_204),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_205),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_206),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_207),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_208),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_209),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_210),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_211),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_212),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_213),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_214),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_215),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_216),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_217),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_218),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_219),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_220),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_221),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_222),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_223),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_224),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_225),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_226),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_227),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_228),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_229),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_230),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_231),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_232),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_233),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_234),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_235),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_236),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_237),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_238),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_239),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_240),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_241),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_242),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_243),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_244),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_245),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_246),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_247),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_248),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_249),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_250),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_251),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_252),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_253),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_254),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_255),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_256),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_257),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_258),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_259),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_260),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_261),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_262),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_263),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_264),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_265),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_266),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_267),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_268),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_269),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_270),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_271),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_272),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_273),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_274),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_275),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_276),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_277),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_278),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_279),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_280),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_281),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_282),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_283),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_284),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_285),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_286),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_287),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_288),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_289),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_290),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_291),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_292),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_293),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_294),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_295),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_296),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_297),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_298),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_299),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_300),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_301),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_302),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_303),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_304),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_305),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_306),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_307),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_308),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_309),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_310),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_311),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_312),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_313),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_314),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_315),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_316),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_317),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_318),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_319),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_320),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_321),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_322),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_323),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_324),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_325),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_326),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_327),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_328),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_329),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_330),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_331),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_332),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_333),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_334),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_335),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_336),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_337),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_338),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_339),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_340),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_341),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_342),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_343),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_344),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_345),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_346),
			#if PLATFORM_IS_USER
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_347),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_348),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_349),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_350),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_351),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_352),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_353),
			CAST_PTR(void*, K_HS_FUNCTION_TABLE_REFERENCE_354),
			#endif
		};
		#pragma endregion

		//////////////////////////////////////////////////////////////////////////
		// script globals related
		ENGINE_PTR(int32, hs_external_globals_count, DUO_PTR(K_HS_EXTERNAL_GLOBALS_COUNT_PTR));
		ENGINE_DPTR(hs_global_definition, hs_external_globals, DUO_PTR(K_HS_EXTERNAL_GLOBALS));

		static int16* K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCES_16bit[] = {
			CAST_PTR(int16*, K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCE_16BIT_0),
		};
		static int32* K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCES_32bit[] = {
			CAST_PTR(int32*, K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCE_32BIT_0),
			CAST_PTR(int32*, K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCE_32BIT_1),
			CAST_PTR(int32*, K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCE_32BIT_2),
			CAST_PTR(int32*, K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCE_32BIT_3),
			CAST_PTR(int32*, K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCE_32BIT_4),
			CAST_PTR(int32*, K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCE_32BIT_5),
			CAST_PTR(int32*, K_HS_EXTERNAL_GLOBALS_COUNT_REFERENCE_32BIT_6),
		};
		static void* K_HS_EXTERNAL_GLOBALS_REFERENCES[] = {
			CAST_PTR(void*, K_HS_EXTERNAL_GLOBALS_REFERENCE_0),
			CAST_PTR(void*, K_HS_EXTERNAL_GLOBALS_REFERENCE_1),
			CAST_PTR(void*, K_HS_EXTERNAL_GLOBALS_REFERENCE_2),
			CAST_PTR(void*, K_HS_EXTERNAL_GLOBALS_REFERENCE_3),
			CAST_PTR(void*, K_HS_EXTERNAL_GLOBALS_REFERENCE_4),
			CAST_PTR(void*, K_HS_EXTERNAL_GLOBALS_REFERENCE_5),
			CAST_PTR(void*, K_HS_EXTERNAL_GLOBALS_REFERENCE_6),
			CAST_PTR(void*, K_HS_EXTERNAL_GLOBALS_REFERENCE_7),
			CAST_PTR(void*, K_HS_EXTERNAL_GLOBALS_REFERENCE_8),
			CAST_PTR(void*, K_HS_EXTERNAL_GLOBALS_REFERENCE_9),
		};

		//////////////////////////////////////////////////////////////////////////

		FUNC_PTR(HS_VALID_ACCESS_FLAGS, DUO_PTR(K_HS_VALID_ACCESS_FLAGS));

		//////////////////////////////////////////////////////////////////////////
		// InitializeCreateScriptFunction()
		FUNC_PTR(HS_ARGUMENTS_EVALUATE, DUO_PTR(K_HS_ARGUMENTS_EVALUATE));
		FUNC_PTR(HS_RETURN, DUO_PTR(K_HS_RETURN));
	}
}
