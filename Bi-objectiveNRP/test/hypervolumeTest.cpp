//
// Created by carlos on 04/12/18.
//
#define BOOST_TEST_MODULE HYPERVOLUME_SUITE
#include <boost/test/unit_test.hpp>
#include <eo>
#include <metric/moeoHyperVolumeMetric.h>
#include <BiObjNRPVectorTraits.h>

std::vector<BiObjNRPObjectiveVector> getVector()
{
    std::vector<BiObjNRPObjectiveVector> testVector;
    for(unsigned int i = 0; i <= 5; i++)
    {
        BiObjNRPObjectiveVector vector;
        vector[0] = i;
        vector[1] = i;
        testVector.push_back(vector);
    }
    return testVector;
}

BOOST_AUTO_TEST_SUITE(hypervolume_test_suite)

    BOOST_AUTO_TEST_CASE(check_automatic_hypervolume)
    {
        // ARRANGE
        moeoHyperVolumeMetric<BiObjNRPObjectiveVector> hypervolume00(true, 1.0);
        std::vector<BiObjNRPObjectiveVector> testVector(getVector());

        // ACT
        double hv = hypervolume00(testVector);

        // ASSERT
        BOOST_TEST(hv == 0.4);
    }

    BOOST_AUTO_TEST_CASE(check_hypervolume_with_reference_point)
    {
        // ARRANGE
        BiObjNRPObjectiveVector refPoint;
        refPoint[0] = 0.0;
        refPoint[1] = 1.0;

        moeoHyperVolumeMetric<BiObjNRPObjectiveVector> hypervolume00(true, refPoint);

        std::vector<BiObjNRPObjectiveVector> testVector(getVector());

        // ACT
        double hv = hypervolume00(testVector);

        // ASSERT
        BOOST_TEST(hv == 0.4);
    }

    BOOST_AUTO_TEST_CASE(check_hypervolume_with_reference_point_and_bounds)
    {
        // ARRANGE
        // El punto de referencia debe estar normalizado para que sea equivalente a los otros constructores
        BiObjNRPObjectiveVector refPoint;
        refPoint[0] = 0.0;
        refPoint[1] = 1.0;

        std::vector<eoRealInterval> bounds(2);
        bounds[0] = eoRealInterval(0.0, 5.0);
        bounds[1] = eoRealInterval(0.0, 5.0);

        moeoHyperVolumeMetric<BiObjNRPObjectiveVector> hypervolume00(refPoint, bounds);

        std::vector<BiObjNRPObjectiveVector> testVector(getVector());

        // ACT
        double hv = hypervolume00(testVector);

        // ASSERT
        BOOST_TEST(hv == 0.4);
    }

    BOOST_AUTO_TEST_CASE(check_hypervolume_with_reference_point_and_bounds_nrp1)
    {
        // ARRANGE
        // El punto de referencia debe estar normalizado para que sea equivalente a los otros constructores
        BiObjNRPObjectiveVector refPoint;
        refPoint[0] = 0.0;
        refPoint[1] = 1.0;

        std::vector<eoRealInterval> bounds(2);
        bounds[0] = eoRealInterval(0.0, 2909.0);
        bounds[1] = eoRealInterval(0.0, 787.0);

        moeoHyperVolumeMetric<BiObjNRPObjectiveVector> hypervolume00(refPoint, bounds);

        std::vector<BiObjNRPObjectiveVector> testVector;

        std::vector<double> vec;
        vec = 	{	0	,	0	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	23	,	1	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	27	,	3	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	50	,	4	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	59	,	7	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	78	,	9	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	86	,	10	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	91	,	12	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	100	,	14	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	114	,	15	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	124	,	16	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	147	,	17	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	160	,	22	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	183	,	23	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	188	,	25	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	197	,	27	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	209	,	28	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	214	,	29	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	220	,	30	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	224	,	31	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	233	,	33	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	240	,	34	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	246	,	35	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	251	,	36	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	255	,	37	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	261	,	38	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	264	,	39	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	270	,	40	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	277	,	41	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	281	,	42	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	287	,	43	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	292	,	44	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	296	,	45	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	301	,	46	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	305	,	47	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	311	,	48	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	318	,	49	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	320	,	50	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	327	,	51	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	331	,	52	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	337	,	53	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	342	,	54	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	346	,	55	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	357	,	57	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	361	,	58	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	368	,	59	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	372	,	61	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	383	,	62	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	387	,	63	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	398	,	65	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	403	,	67	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	406	,	68	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	411	,	69	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	424	,	70	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	427	,	71	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	433	,	73	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	447	,	76	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	452	,	77	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	464	,	78	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	468	,	79	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	472	,	82	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	476	,	83	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	487	,	84	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	492	,	85	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	505	,	86	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	516	,	88	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	528	,	92	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	533	,	93	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	540	,	94	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	553	,	95	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	557	,	96	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	563	,	100	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	576	,	101	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	581	,	102	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	594	,	103	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	604	,	108	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	617	,	109	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	622	,	110	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	629	,	111	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	634	,	114	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	645	,	116	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	652	,	117	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	657	,	118	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	662	,	121	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	669	,	122	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	673	,	123	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	680	,	124	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	688	,	125	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	692	,	128	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	697	,	129	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	698	,	130	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	711	,	131	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	716	,	132	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	720	,	135	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	728	,	136	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	739	,	138	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	744	,	139	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	751	,	142	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	756	,	143	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	767	,	145	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	769	,	146	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	772	,	147	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	779	,	149	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	784	,	150	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	792	,	152	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	797	,	153	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	803	,	154	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	807	,	156	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	809	,	157	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	812	,	158	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	820	,	159	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	831	,	161	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	837	,	164	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	843	,	165	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	848	,	167	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	859	,	168	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	862	,	170	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	871	,	172	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	876	,	174	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	889	,	175	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	899	,	179	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	904	,	181	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	917	,	182	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	929	,	186	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	945	,	189	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	957	,	193	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	973	,	197	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	977	,	199	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	985	,	200	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	994	,	204	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	999	,	205	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1005	,	206	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1013	,	208	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1017	,	210	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1022	,	212	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1033	,	213	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1035	,	214	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1040	,	216	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1045	,	217	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1050	,	219	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1063	,	220	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1068	,	223	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1073	,	224	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1075	,	225	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1078	,	226	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1091	,	227	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1096	,	230	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1103	,	231	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1106	,	233	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1119	,	234	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1121	,	235	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1131	,	238	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1137	,	240	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1145	,	241	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1149	,	242	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1159	,	245	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1161	,	246	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1165	,	247	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1170	,	248	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1177	,	249	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1185	,	252	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1189	,	253	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1193	,	254	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1198	,	255	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1204	,	256	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1218	,	260	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1220	,	261	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1226	,	262	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1230	,	263	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1238	,	266	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1246	,	267	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1254	,	269	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1257	,	270	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1258	,	271	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1264	,	272	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1267	,	273	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1274	,	274	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1276	,	275	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1284	,	276	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1287	,	278	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1295	,	279	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1300	,	281	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1304	,	282	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1312	,	283	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1315	,	284	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1323	,	286	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1324	,	287	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1332	,	289	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1340	,	290	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1343	,	291	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1351	,	293	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1353	,	294	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1359	,	296	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1366	,	297	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1371	,	298	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1373	,	299	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1381	,	300	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1385	,	303	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1398	,	305	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1401	,	306	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1409	,	307	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1425	,	312	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1429	,	313	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1437	,	314	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1439	,	315	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1451	,	319	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1456	,	320	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1463	,	321	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1467	,	322	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1482	,	327	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1495	,	329	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1508	,	335	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1522	,	336	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1548	,	343	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1554	,	348	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1560	,	350	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1574	,	351	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1581	,	355	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1586	,	357	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1599	,	360	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1607	,	362	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1609	,	364	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1612	,	365	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1615	,	366	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1625	,	367	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1633	,	370	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1636	,	371	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1641	,	373	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1651	,	375	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1662	,	378	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1669	,	381	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1678	,	383	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1682	,	385	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1685	,	386	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1696	,	388	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1704	,	390	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1708	,	393	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1710	,	394	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1722	,	395	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1730	,	398	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1739	,	402	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1748	,	403	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1754	,	406	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1760	,	409	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1763	,	410	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1772	,	411	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1780	,	413	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1782	,	414	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1789	,	417	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1798	,	418	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1802	,	420	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1810	,	421	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1816	,	424	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1818	,	425	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1824	,	426	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1829	,	427	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1836	,	428	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1840	,	429	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1843	,	431	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1855	,	434	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1858	,	435	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1868	,	436	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1884	,	442	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1895	,	443	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1903	,	449	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1921	,	450	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1924	,	451	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1927	,	453	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1943	,	457	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1950	,	458	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1954	,	459	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1969	,	464	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1982	,	466	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	1995	,	472	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2009	,	473	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2017	,	479	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2035	,	480	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2047	,	487	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2061	,	488	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2067	,	493	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2073	,	494	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2075	,	495	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2084	,	496	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2086	,	498	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2089	,	499	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2094	,	500	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2096	,	501	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2103	,	502	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2105	,	503	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2110	,	504	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2115	,	506	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2120	,	507	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2123	,	508	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2130	,	509	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2136	,	511	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2139	,	512	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2143	,	513	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2147	,	514	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2152	,	515	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2156	,	516	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2158	,	517	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2166	,	519	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2169	,	520	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2174	,	521	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2180	,	522	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2186	,	524	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2193	,	525	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2195	,	527	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2201	,	528	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2206	,	529	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2210	,	530	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2224	,	531	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2229	,	535	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2240	,	537	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2252	,	538	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2260	,	541	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2268	,	544	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2278	,	545	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2281	,	546	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2288	,	548	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2295	,	550	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2300	,	551	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2304	,	552	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2307	,	553	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2314	,	555	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2320	,	556	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2330	,	557	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2332	,	559	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2335	,	560	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2338	,	561	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2340	,	562	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2357	,	563	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2358	,	564	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2363	,	566	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2366	,	567	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2368	,	568	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2378	,	569	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2386	,	570	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2393	,	572	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2403	,	575	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2416	,	576	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2420	,	578	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2421	,	579	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2425	,	581	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2443	,	582	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2449	,	585	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2452	,	586	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2456	,	588	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2471	,	589	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2479	,	591	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2483	,	594	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2497	,	596	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2506	,	597	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2511	,	601	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2516	,	603	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2534	,	604	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2542	,	610	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2560	,	611	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2581	,	621	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2589	,	624	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2594	,	627	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2600	,	632	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2602	,	633	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2620	,	634	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2626	,	639	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2628	,	640	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2641	,	644	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2652	,	646	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2654	,	647	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2657	,	648	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2665	,	654	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2683	,	655	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2704	,	665	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2712	,	668	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2717	,	671	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2723	,	676	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2725	,	677	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2743	,	678	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2764	,	688	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2777	,	694	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2783	,	699	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2804	,	704	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2825	,	714	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2844	,	725	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2865	,	743	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2885	,	761	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));
        vec = 	{	2909	,	787	}	;	testVector.push_back(BiObjNRPObjectiveVector(vec));


        // ACT
        double hv = hypervolume00(testVector);

        // ASSERT
        BOOST_TEST(hv == 0.57481731977567729);
    }



BOOST_AUTO_TEST_SUITE_END()