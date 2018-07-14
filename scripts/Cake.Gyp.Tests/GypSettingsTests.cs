﻿using System.Collections.Generic;
using Cake.Core.IO;
using FluentAssertions;
using Xunit;

namespace Cake.Gyp.Tests
{
	public class GypSettingsTests
	{
		private static readonly DirectoryPath sOutputDirectory = DirectoryPath.FromString("anyDirectory");

		public static IEnumerable<object[]> TestSettings =>
			new[]
			{
				new object[]
				{
					new GypSettings
					{
						OutputPlatform = GypOutputPlatform.Make,
						OutputDirectory = sOutputDirectory
					},
					"-f make --generator-output=\"anyDirectory\""
				},
				new object[]
				{
					new GypSettings
					{
						OutputPlatform = GypOutputPlatform.XCode,
						OutputDirectory = sOutputDirectory
					},
					"-f xcode --generator-output=\"anyDirectory\""
				},
				new object[]
				{
					new GypSettings
					{
						OutputPlatform = GypOutputPlatform.VisualStudio2013,
						OutputDirectory = sOutputDirectory
					},
					"-f msvs -G msvs_version=2013 --generator-output=\"anyDirectory\""
				},
				new object[]
				{
					new GypSettings
					{
						OutputPlatform = GypOutputPlatform.VisualStudio2015,
						OutputDirectory = sOutputDirectory
					},
					"-f msvs -G msvs_version=2015 --generator-output=\"anyDirectory\""
				},
				new object[]
				{
					new GypSettings
					{
						OutputPlatform = GypOutputPlatform.VisualStudio2017,
						OutputDirectory = sOutputDirectory
					},
					"-f msvs -G msvs_version=2017 --generator-output=\"anyDirectory\""
				},
				new object[]
				{
					new GypSettings
					{
						OutputPlatform = GypOutputPlatform.Ninja,
						OutputDirectory = sOutputDirectory
					},
					"-f ninja --generator-output=\"anyDirectory\""
				}
			};

		[Theory]
		[MemberData(nameof(TestSettings))]
		public void GetArguments_WithParameterSet_ReturnsArguments(GypSettings settings, string expected)
		{
			ProcessArgumentBuilder result = settings.GetArguments();

			result.Render().Should().Be(expected);
		}
	}
}
