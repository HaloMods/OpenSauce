﻿/*
    BlamLib: .NET SDK for the Blam Engine

    Copyright (C) 2005-2010  Kornner Studios (http://kornner.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
using System;
using System.Collections.Generic;
using StringID = BlamLib.Blam.StringID;
using GenerateIdMethod = BlamLib.Blam.StringID.GenerateIdMethod;

namespace BlamLib.Managers
{
	public interface IStringIdContainer
	{
		/// <summary>Interface for enumerating through all the IDs and their values in this container</summary>
		/// <returns></returns>
		IEnumerable<KeyValuePair<StringID, string>> StringIdsEnumerator();

		/// <summary>Determines if the ID exists in this container</summary>
		/// <param name="sid"></param>
		/// <returns></returns>
		bool ContainsStringId(StringID sid);

		/// <summary>Lookup an ID's value</summary>
		/// <param name="sid">ID to get the value for</param>
		/// <returns></returns>
		/// <exception cref="ArgumentOutOfRangeException"><paramref name="sid"/> is invalid</exception>
		/// <exception cref="KeyNotFoundException"><paramref name="sid"/> was not found in this container</exception>
		string GetStringIdValue(StringID sid);

		/// <summary> </summary>
		/// <param name="absolute_index"></param>
		/// <returns></returns>
		/// <exception cref="ArgumentOutOfRangeException"><paramref name="absolute_index"/> is out the range of this container</exception>
		string GetStringIdValueUnsafe(short absolute_index);

		/// <summary>Find an ID based on its string</summary>
		/// <param name="value">String value to find</param>
		/// <param name="sid"><paramref name="value"/>'s associated ID, or <see cref="Data.StringId.kInvalid"/> if this fails</param>
		/// <returns>True if an ID exists for the value</returns>
		/// <remarks>
		/// If the string is not found, the implementing class has the option of adding the string and 
		/// returning the new ID. It all depends on the context and if <see cref="IsReadOnly"/> is false
		/// </remarks>
		/// <exception cref="ArgumentNullException"><paramref name="value"/> is null</exception>
		bool TryAndGetStringId(string value, out StringID sid);

		/// <summary>Does this container allow new ids to be added from dynamic strings?</summary>
		bool IsReadOnly { get; }
	};

	internal sealed class StringIdCollectionDefintion
	{
		#region HandleMethod
		GenerateIdMethod m_handleMethod;
		/// <summary>Method used which to create new handles</summary>
		public GenerateIdMethod HandleMethod { get { return m_handleMethod; } }
		#endregion

		/// <summary>Set to add new (non-predefined) string ids to</summary>
		/// <remarks>Default is 0</remarks>
		public int SetForAdding { get; private set; }
		/// <summary>Index to start new (non-predefined) string ids at</summary>
		/// <remarks>Default is 0</remarks>
		public int InitialIndexForAdding { get; private set; }

		internal StringIdCollectionDefintion() { }

		public StringIdCollectionDefintion(GenerateIdMethod method, 
			int set_for_adding, int initial_index_for_adding)
		{
			if (set_for_adding < 0) throw new ArgumentOutOfRangeException("set_for_adding", set_for_adding, "Must be greater than or equal to zero");
			if (initial_index_for_adding < 0) throw new ArgumentOutOfRangeException("initial_index_for_adding", initial_index_for_adding, "Must be greater than or equal to zero");

			m_handleMethod = method;

			SetForAdding = set_for_adding;
			InitialIndexForAdding = initial_index_for_adding;
		}
		public StringIdCollectionDefintion(GenerateIdMethod method) : this(method, 0, 0) { }

		/// <summary>If the initial index for adding is zero, calculate the index based on the supplied sets</summary>
		/// <param name="static_collection"></param>
		internal void CalculateInitialIdForAdding(StringIdStaticCollection static_collection)
		{
			if (InitialIndexForAdding == 0)
				InitialIndexForAdding = static_collection.SetFromId(SetForAdding).Count;
		}
		public StringID GenerateInitialIdForAdding()
		{
			return new StringID((short)InitialIndexForAdding, 0, (byte)SetForAdding);
		}

		#region IXmlElementStreamable Members
		bool HasAddSetOverrides() { return SetForAdding > 0 || InitialIndexForAdding > 0; }

		void StreamFromXml(IO.XmlStream s, out int set, out int initial_index)
		{
			set = initial_index = 0;

			s.ReadAttribute("set", ref set);
			s.ReadAttributeOpt("initialIndex", ref initial_index);
		}

		public void StreamXml(IO.XmlStream s)
		{
			s.ReadAttribute("method", ref m_handleMethod);

			int set_index, set_initial_index;
			foreach (System.Xml.XmlNode n in s.Cursor.ChildNodes)
				if (n.Name == "adding")
				{
					s.SaveCursor(n as System.Xml.XmlElement);
						StreamFromXml(s, out set_index, out set_initial_index);
					s.RestoreCursor();

					SetForAdding = set_index;
					InitialIndexForAdding = set_initial_index;
				}
		}
		#endregion
	};

	sealed class StringIdSet
	{
		/// <summary>When a string id value is undefined, this will be the value's prefix</summary>
		public const string kDefaultValuePrefix = "string_id_";
		/// <summary>When a set's name is undefined, this will be the set's default name</summary>
		const string kDefaultName = "UNKNOWN";

		internal int Index { get; private set; }

		public int Id { get; private set; }
		public string Name { get; private set; }
		public Dictionary<StringID, string> Set { get; internal set; }
		/// <summary>Look-up table for this set</summary>
		/// <remarks>TKey=string hash code, TValue=Id for the string</remarks>
		public Dictionary<int, StringID> SetLookup { get; internal set; }

		public int Count { get { return Set.Count; } }

		#region Ctor
		void InitializeSets(int capacity)
		{
			if (capacity <= 0)
			{
				Set = new Dictionary<StringID, string>(StringID.kEqualityComparer);
				SetLookup = new Dictionary<int, StringID>();
			}
			else
			{
				Set = new Dictionary<StringID, string>(capacity, StringID.kEqualityComparer);
				SetLookup = new Dictionary<int, StringID>(capacity);
			}
		}

		public StringIdSet(int index, IO.XmlStream s)
		{
			Index = index;

			StreamFromXml(s);
		}

		public StringIdSet(int index, string name, int id, int capacity)
		{
			Index = index;

			Id = id;
			Name = name ?? kDefaultName;

			InitializeSets(capacity);
		}
		#endregion

		#region IXmlElementStreamable Members
		public void StreamFromXml(IO.XmlStream s)
		{
			int set_id = -1;
			string set_name = null;
			s.ReadAttribute("key", 10, ref set_id);
			s.ReadAttributeOpt("value", ref set_name);

			Id = set_id;
			Name = set_name ?? kDefaultName;

			InitializeSets(s.Cursor.ChildNodes.Count);

			string val; StringID sid = StringID.kInvalid;
			foreach (System.Xml.XmlNode n in s.Cursor.ChildNodes)
			{
				if (n.Name != "entry") continue;

				val = null;

				s.SaveCursor(n as System.Xml.XmlElement);
					s.ReadAttribute("key", 16, ref sid.Handle);
					s.ReadAttributeOpt("value", ref val);
				s.RestoreCursor();

				// If the definition didn't specify the value, generate a generic value as a placeholder
				if (val == null)
					val = string.Format("{0}{1}", kDefaultValuePrefix, sid.Handle.ToString("X8"));

				Set.Add(sid, val);
				SetLookup.Add(val.GetHashCode(), sid);
			}
		}
		#endregion
	};

	sealed class StringIdStaticCollection : IStringIdContainer, IDisposable, BlamDefinition.IGameResource
	{
		/// <summary>The base definition of this manager</summary>
		public StringIdCollectionDefintion Definition { get; private set; }

		/// <summary>Sets for predefined ids (static)</summary>
		List<StringIdSet> m_sets;

		#region Count
		int m_count;
		public int Count { get { return m_count; } }

		void CalculateCount()
		{
			m_count = 0;

			foreach (var set in m_sets)
				m_count += set.Count;
		}
		#endregion

		public StringIdStaticCollection()
		{
		}

		#region Set Util
		bool SetIsValid(byte set_index)	{ return set_index >= 0 && set_index < m_sets.Count; }

		StringIdSet SetFromIndex(int index)
		{
			foreach(var set in m_sets)
				if(set.Index == index) return set;

			return null;
		}
		internal StringIdSet SetFromId(int id)
		{
			foreach (var set in m_sets)
				if (set.Id == id) return set;

			return null;
		}
		#endregion

		public IEnumerable<KeyValuePair<StringID, string>> GetEnumerator()
		{
			foreach(var set in m_sets)
				foreach(var kv in set.Set)
					yield return kv;
		}

		internal string GetValue(StringID sid)
		{
			if (SetIsValid(sid.Set))
			{
				var set = SetFromId(sid.Set);
				if(sid.Index < set.Count)
					return set.Set[sid];
			}

			return null;
		}
		internal string GetValueUnsafe(short absolute_index)
		{
			int index = absolute_index;
			foreach (var set in m_sets)
			{
				if (index >= 0 && index < set.Count)
				{
					foreach (var kv in set.Set)
						if (kv.Key.Index == index)
							return kv.Value;
				}

				index -= set.Count;
			}

			return null;
		}

		#region DebugStream Utils
		/// <summary>Build debug streams which foreign native code can easily interop with</summary>
		/// <param name="offsets">Buffer containing the offsets of the string values in <paramref name="buffer"/></param>
		/// <param name="buffer">Buffer containing the string values</param>
		/// <param name="pack">If true, the strings are stored as null terminated strings, else in 128 character strings</param>
		public void ToDebugStream(IO.EndianWriter offsets, IO.EndianWriter buffer, bool pack)
		{
			foreach(var set in m_sets)
				foreach (var kv in set.Set)
				{
					offsets.Write(buffer.Position);
					if (pack) buffer.Write(kv.Value, true);
					else buffer.Write(kv.Value, 128);
				}
		}
		/// <summary></summary>
		/// <param name="offsets">Buffer containing the offsets of the string values in <paramref name="buffer"/></param>
		/// <param name="buffer">Buffer containing the string values</param>
		/// <param name="is_packed">If true, reads the strings as null terminated strings, else as 128 character strings</param>
		/// <remarks>
		/// Doesn't actually populate the collection from a debug stream. Instead it seeks the streams to directly after this set's 
		/// data, assuming the streams have data which matches this collection. Also assumes the streams aren't filled with just static 
		/// strings, but also contain dynamic string data as well (or else the seek operations this performs will exception)
		/// </remarks>
		public void FromDebugStream(IO.EndianReader offsets, IO.EndianReader buffer, bool is_packed)
		{
			int last_offset = sizeof(uint) * Count;

			offsets.Seek(last_offset);
			int last_offset_buffer = offsets.ReadInt32();

			buffer.Seek(last_offset_buffer);
		}
		#endregion

		#region IXmlElementStreamable Members
		void StreamSetsFromXml(IO.XmlStream s)
		{
			m_sets = new List<StringIdSet>(s.Cursor.ChildNodes.Count);

			int index = 0;
			foreach (System.Xml.XmlNode n in s.Cursor.ChildNodes)
				if (n.Name == "Set")
				{
					s.SaveCursor(n as System.Xml.XmlElement);
						var set = new StringIdSet(index, s);
					s.RestoreCursor();

					m_sets.Add(set);
					index++;
				}

			m_sets.TrimExcess();
			CalculateCount();
		}
		public void StreamFromXml(IO.XmlStream s)
		{
			foreach (System.Xml.XmlNode n in s.Cursor.ChildNodes)
				if (n.Name == "definition")
				{
					s.SaveCursor(n as System.Xml.XmlElement);
						Definition = new StringIdCollectionDefintion();
						Definition.StreamXml(s);
					s.RestoreCursor();
				}
				else if (n.Name == "sets")
				{
					s.SaveCursor(n as System.Xml.XmlElement);
						StreamSetsFromXml(s);
					s.RestoreCursor();
				}

			Definition.CalculateInitialIdForAdding(this);
		}
		#endregion

		/// <summary>
		/// Load the string id data from an xml manifest file
		/// </summary>
		/// <param name="path"></param>
		/// <param name="name"></param>
		public bool Load(string path, string name)
		{
			using (IO.XmlStream s = new BlamLib.IO.XmlStream(path, name, this))
			{
				StreamFromXml(s);
			}

			return true;
		}

		#region IDisposable Members
		public void Close()
		{
			if (m_sets != null)
			{
				m_sets.Clear();
				m_sets = null;
				m_count = 0;
			}
		}
		public void Dispose() { Close(); }
		#endregion

		#region IStringIdContainer Members
		IEnumerable<KeyValuePair<StringID, string>> IStringIdContainer.StringIdsEnumerator()
		{
			return GetEnumerator();
		}

		/// <summary>Determines if the ID exists in this container</summary>
		/// <param name="sid"></param>
		/// <returns></returns>
		public bool ContainsStringId(StringID sid)
		{
			if (SetIsValid(sid.Set))
				return SetFromId(sid.Set).Set.ContainsKey(sid);

			return false;
		}

		string IStringIdContainer.GetStringIdValue(StringID sid)
		{
			string value = GetValue(sid);

			if(value == null)
				throw new KeyNotFoundException(sid.ToString());

			return value;
		}

		string IStringIdContainer.GetStringIdValueUnsafe(short absolute_index)
		{
			string value = GetValueUnsafe(absolute_index);

			if (value == null)
				throw new ArgumentOutOfRangeException(absolute_index.ToString("X4"));

			return value;
		}

		public bool TryAndGetStringId(string value, out StringID sid)
		{
			sid = StringID.kInvalid;

			var hc = value.GetHashCode();
			foreach(var set in m_sets)
			{
				StringID tgv;
				if(set.SetLookup.TryGetValue(hc, out tgv))
				{
					sid = tgv;
					return true;
				}
			}

			return false;
		}

		/// <summary>Does this container allow new ids to be added from dynamic strings?</summary>
		/// <remarks>ALWAYS returns true</remarks>
		bool IStringIdContainer.IsReadOnly { get { return true; } }
		#endregion
	};

	sealed class StringIdDynamicCollection : IStringIdContainer, IEnumerable<KeyValuePair<StringID, string>>
	{
		#region HandleMethod
		GenerateIdMethod m_handleMethod;
		/// <summary>Method used which to create new handles</summary>
		public GenerateIdMethod HandleMethod { get { return m_handleMethod; } }
		#endregion

		StringIdSet m_set;

		/// <summary>ID of the first string in this dynamic collection</summary>
		/// <remarks>Getter is private as no outside code should ever need to get this</remarks>
		internal StringID InitialId { private get; set; }

		public int Count { get { return m_set.Count; } }

		#region Construction
		void InitializeSet(int capacity)
		{
			m_set = new StringIdSet(-1, "dynamic globals", InitialId.Set, capacity);
		}
		public StringIdDynamicCollection(GenerateIdMethod method, StringID initial_id, int capacity)
		{
			m_handleMethod = method;

			InitialId = initial_id;
			IsReadOnly = false;

			InitializeSet(capacity);
		}
		public StringIdDynamicCollection(GenerateIdMethod method, StringID initial_id) : this(method, initial_id, 0) {}
		#endregion

		bool SetIsValid(byte set_index) { return InitialId.Set == set_index; }

		StringID Add(string value)
		{
			var gen_func = StringID.GetGenerateFunc(m_handleMethod);

			var sid = gen_func((short)(Count-1), (byte)value.Length, InitialId.Set);
			m_set.Set.Add(sid, value);
			m_set.SetLookup.Add(value.GetHashCode(), sid);

			return sid;
		}

		internal string GetValue(StringID sid)
		{
			if (SetIsValid(sid.Set))
				return m_set.Set[sid];

			return null;
		}
		internal string GetValueUnsafe(short absolute_index)
		{
			int index = absolute_index;
			if (index >= 0 && index < Count)
			{
				foreach (var kv in m_set.Set)
					if (kv.Key.Index == index)
						return kv.Value;
			}

			return null;
		}

		#region DebugStream Utils
		/// <summary>Build debug streams which foreign native code can easily interop with</summary>
		/// <param name="offsets">Buffer containing the offsets of the string values in <paramref name="buffer"/></param>
		/// <param name="buffer">Buffer containing the string values</param>
		/// <param name="pack">If true, the strings are stored as null terminated strings, else in 128 character strings</param>
		public void ToDebugStream(IO.EndianWriter offsets, IO.EndianWriter buffer, bool pack)
		{
			foreach (var kv in m_set.Set)
			{
				offsets.Write(buffer.Position);
				if (pack) buffer.Write(kv.Value, true);
				else buffer.Write(kv.Value, 128);
			}
		}
		/// <summary></summary>
		/// <param name="offsets">Buffer containing the offsets of the string values in <paramref name="buffer"/></param>
		/// <param name="buffer">Buffer containing the string values</param>
		/// <param name="is_packed">If true, reads the strings as null terminated strings, else as 128 character strings</param>
		/// <param name="count">Number of dynamic strings for <paramref name="set_index"/></param>
		/// <remarks>
		/// Doesn't use <paramref name="offsets"/> for reading the strings, assumes the strings are in sequential order in <paramref name="buffer"/>.
		/// 
		/// Ignores <see cref="IsReadOnly"/>; will always add new IDs.
		/// </remarks>
		public void FromDebugStream(IO.EndianReader offsets, IO.EndianReader buffer, 
			bool is_packed, int count)
		{
			if (count <= 0) throw new ArgumentOutOfRangeException("count", count, "Must be greater than zero");

			var gen_func = StringID.GetGenerateFunc(m_handleMethod);

			// Assume the strings are in sequential order in [buffer]
			offsets.Seek(sizeof(uint) * count, System.IO.SeekOrigin.Current);

			int set_index = InitialId.Set, initial_index = InitialId.Index;

			InitializeSet(count);
			for (int x = 0; x < count; x++)
			{
				var str = is_packed ? buffer.ReadCString() : buffer.ReadAsciiString(128);
				var sid = gen_func((short)(initial_index + x), (byte)str.Length, (byte)set_index);

				m_set.Set.Add(sid, str);
				m_set.SetLookup.Add(str.GetHashCode(), sid);
			}
		}
		#endregion

		#region IEnumerable<KeyValuePair<StringId,string>> Members
		public IEnumerator<KeyValuePair<StringID, string>> GetEnumerator()
		{
			return m_set.Set.GetEnumerator();
		}

		System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
		{
			return m_set.Set.GetEnumerator();
		}
		#endregion

		#region IStringIdContainer Members
		IEnumerable<KeyValuePair<StringID, string>> IStringIdContainer.StringIdsEnumerator()
		{
			foreach (var kv in m_set.Set)
				yield return kv;
		}

		/// <summary>Determines if the ID exists in this container</summary>
		/// <param name="sid"></param>
		/// <returns></returns>
		public bool ContainsStringId(StringID sid)
		{
			if (SetIsValid(sid.Set))
				return m_set.Set.ContainsKey(sid);

			return false;
		}

		string IStringIdContainer.GetStringIdValue(StringID sid)
		{
			string value = GetValue(sid);

			if(value == null)
				throw new KeyNotFoundException(sid.ToString());

			return value;
		}

		string IStringIdContainer.GetStringIdValueUnsafe(short absolute_index)
		{
			string value = GetValueUnsafe(absolute_index);

			if (value == null)
				throw new ArgumentOutOfRangeException(absolute_index.ToString("X4"));

			return value;
		}

		public bool TryAndGetStringId(string value, out StringID sid)
		{
			sid = StringID.kInvalid;
			bool result = false;

			#region Try to find
			var hc = value.GetHashCode();
			StringID tgv;
			if (m_set.SetLookup.TryGetValue(hc, out tgv))
			{
				sid = tgv;
				result = true;
			}
			#endregion
			#region Try to add
			else if (!IsReadOnly)
			{
				sid = Add(value);
				result = true;
			}
			#endregion

			return result;
		}

		/// <summary>Does this container allow new ids to be added from dynamic strings?</summary>
		public bool IsReadOnly { get; set; }
		#endregion
	};
}